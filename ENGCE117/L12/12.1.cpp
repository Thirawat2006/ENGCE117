#include <stdio.h>
#include <stdlib.h>

int *dijkstra(int *L, int n);

int main() {
    int n = 5; 
    int i, j; 
    int *d, *g;
    
    // จองพื้นที่ Adjacency Matrix [cite: 1701-1703]
    g = (int *)malloc(n * n * sizeof(int)); 
    
    // กำหนดค่าเริ่มต้นกราฟ [cite: 1704-1706]
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            g[i * n + j] = -1; 

    // กำหนดน้ำหนักเส้นทางตามสไลด์หน้า 9 และ 40 [cite: 1520-1533, 1707-1715]
    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;  g[0 * n + 4] = 10;
    g[1 * n + 2] = 25;  g[3 * n + 1] = 20;
    g[3 * n + 2] = 40;  g[4 * n + 3] = 10;

    d = dijkstra(g, n); // เรียกใช้งานอัลกอริทึม [cite: 1725]
    
    // แสดงผลลัพธ์: 40 60 20 10 [cite: 1719, 1727]
    for(i = 0; i < n - 1; i++)
        printf("%d ", d[i]);
    
    return 0;
}

int *dijkstra(int *L, int n) {
    // D เก็บระยะทางประมวลผล, visited แทนเซ็ต C ของเมืองที่เลือกแล้ว [cite: 1662, 1695-1696]
    int *D = (int *)malloc(n * sizeof(int)); 
    int *visited = (int *)calloc(n, sizeof(int)); 
    
    // 1. กำหนดค่าเริ่มต้น D[i] := L[1,i] จากเมืองแรก [cite: 1663-1664, 1678-1679]
    for (int i = 0; i < n; i++) {
        D[i] = L[0 * n + i]; 
    }
    
    visited[0] = 1; // เริ่มต้นที่เมืองต้นทาง (เมือง 1) [cite: 1551, 1662]
    
    // 2. วนซ้ำ n-2 ครั้ง เพื่อเลือกเมืองที่เหลือในเซ็ต C [cite: 1665, 1680]
    for (int count = 0; count < n - 2; count++) {
        int v = -1;
        int min_dist = -1;

        // เลือกเมือง v ที่มีค่า D[v] น้อยที่สุด (minimizing D[v]) [cite: 1666-1667, 1684]
        for (int i = 1; i < n; i++) {
            if (!visited[i] && D[i] != -1) {
                if (min_dist == -1 || D[i] < min_dist) {
                    min_dist = D[i];
                    v = i;
                }
            }
        }

        if (v == -1) break; 
        visited[v] = 1; // C := C - {v} [cite: 1668, 1684]

        // 3. ปรับปรุงระยะทาง D[w] := min(D[w], D[v] + L[v, m]) [cite: 1669-1670, 1688]
        for (int w = 1; w < n; w++) {
            if (!visited[w] && L[v * n + w] != -1) {
                int new_dist = D[v] + L[v * n + w];
                if (D[w] == -1 || new_dist < D[w]) {
                    D[w] = new_dist;
                }
            }
        }
    }

    // เตรียมคืนค่า D สำหรับเมือง 2 ถึง n ตามรูปแบบ Test Case [cite: 1671, 1726-1727]
    int *result = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        result[i] = D[i + 1];
    }
    
    free(D);
    free(visited);
    return result; // return D [cite: 1671, 1735]
}
