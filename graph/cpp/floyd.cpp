int adjMat[N][N];

for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adjMat[i][k] == -1 || adjMat[k][i] == -1) continue;
            if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) 
                adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
        }
    }
}