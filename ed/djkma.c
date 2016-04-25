#include <string.h> //memset
// MAXV é uma constante que define a quantidade máxima de vértices
#define MAXV 100
// Matriz de adjacências
// Se G[i][j] > 0, então há aresta que liga 'i' a 'j' com custo G[i][j].
int G[MAXV][MAXV];
int V; // quantidade de vértices no grafo G
// Armazena a distância mínima partindo de um vértice 'Vi' até todos os outros vértices
// dis[i] representa a menor distância de 'Vi' a 'i'.
int dis[MAXV];
void dijkstra (int Vi){ // calcula dis[]
    char vis[MAXV];
    memset (vis, 0, sizeof (vis));
    memset (dis, 0x7f, sizeof (dis));
    dis[Vi] = 0;
    int t, i;
    for (t = 0; t < V; t++){
        int v = -1;
        for (i = 0; i < V; i++)
            if (!vis[i] && (v < 0 || dis[i] < dis[v]))
                v = i;
        vis[v] = 1;
        for (i = 0; i < V; i++)
            if (G[v][i] && dis[i] > dis[v] + G[v][i])
                dis[i] = dis[v] + G[v][i];
    }
}

int main(){

    return 0;
}
