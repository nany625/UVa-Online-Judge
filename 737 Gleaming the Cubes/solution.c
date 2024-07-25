#include <stdio.h>

int main() {
	int cubes;
	while(scanf("%d", &cubes) && cubes != 0) {
	    int x, y, z, dist;
	    scanf("%d %d %d %d", &x, &y, &z, &dist);
	    int minX = x, maxX = x + dist, minY = y, maxY = y + dist, minZ = z, maxZ = z + dist;
	    --cubes;
	    while(cubes--) {
	        scanf("%d %d %d %d", &x, &y, &z, &dist);
	        minX = minX > x ? minX : x;
	        maxX = maxX < x + dist ? maxX : x + dist;
	        minY = minY > y ? minY : y;
	        maxY = maxY < y + dist ? maxY : y + dist;
	        minZ = minZ > z ? minZ : z;
	        maxZ = maxZ < z + dist ? maxZ : z + dist;
	    }
	    if(maxX < minX || maxY < minY || maxZ < minZ)
	        puts("0");
	    else
	        printf("%d\n", (maxX - minX) * (maxY - minY) * (maxZ - minZ));
	}
	return 0;
}
