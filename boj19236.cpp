#include <iostream>
using namespace std;

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Fish {
    int y;
    int x;
    int direction;
};

Fish fish[17];
int fishpos[4][4];
bool deadfish[17];

#define SHARK_ID 17
#define EMPTY 0

void backupFishInfo(Fish dest[4][4], Fish src[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dest[i][j] = src[i][j];
}

bool isInboundary(int i, int j) {
    return (i >= 0 && i < 4 && j >= 0 && j < 4);
}

int maxValue = 0;

void dfs(Fish shark, int totFish, int currentPos[4][4], Fish* fish, bool* deadInfo) {
    for (int fishId = 1; fishId <= 16; fishId++) {
        if (deadInfo[fishId]) continue;

        Fish info = fish[fishId];
        int currentPosX = info.x;
        int currentPosY = info.y;

        for (int k = 0; k < 8; k++) {
            int nextDirction = (info.direction + k) % 8;
            int nextPosX = info.x + dx[nextDirction];
            int nextPosY = info.y + dy[nextDirction];

            if (!isInboundary(nextPosX, nextPosY)) continue;
            if (currentPos[nextPosY][nextPosX] == SHARK_ID) continue;

            if (currentPos[nextPosY][nextPosX] == EMPTY) {
                fish[fishId] = { nextPosY, nextPosX, nextDirction };
                currentPos[nextPosY][nextPosX] = fishId;
                currentPos[info.y][info.x] = 0;
                break;
            } else {
                fish[fishId].direction = nextDirction;
                swap(fish[fishId].y, fish[currentPos[nextPosY][nextPosX]].y);
                swap(fish[fishId].x, fish[currentPos[nextPosY][nextPosX]].x);
                swap(currentPos[currentPosY][currentPosX], currentPos[nextPosY][nextPosX]);
                break;
            }
        }
    }

    int nextX = shark.x + dx[shark.direction];
    int nextY = shark.y + dy[shark.direction];

    bool sharkmoved = false;

    while (isInboundary(nextX, nextY)) {
        Fish fishDup[17];
        bool deadDup[17];
        int currentPosDup[4][4];

        for (int i = 1; i <=16; i++) fishDup[i] = fish[i];
        for (int i = 1; i <=16; i++) deadDup[i] = deadInfo[i];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                currentPosDup[i][j] = currentPos[i][j];

        if (currentPosDup[nextY][nextX] != EMPTY) {
            int newDeadFish = currentPosDup[nextY][nextX];

            currentPosDup[nextY][nextX] = SHARK_ID;
            currentPosDup[shark.y][shark.x] = 0;
            deadDup[newDeadFish] = true;

            dfs({ nextY, nextX, fish[newDeadFish].direction }, totFish + newDeadFish, currentPosDup, fishDup, deadDup);
            sharkmoved = true;
        }

        nextX += dx[shark.direction];
        nextY += dy[shark.direction];
    }

    if (!sharkmoved) {
        maxValue = max(maxValue, totFish);
    }
}

int main() {
    int tot_fishnum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int id, direction;
            cin >> id >> direction;

            fishpos[i][j] = id;
            fish[id] = { i, j, direction - 1 };
        }
    }

    tot_fishnum = fishpos[0][0];
    deadfish[fishpos[0][0]] = true;
    fishpos[0][0] = SHARK_ID;

    dfs({ 0, 0, fish[tot_fishnum].direction }, tot_fishnum, fishpos, fish, deadfish);

    cout << maxValue << endl;
}
