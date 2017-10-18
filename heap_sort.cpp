#include <stdio.h>

int heap[11] = {0, 16, 4, 10, 14,7, 9, 3, 2, 8, 1 };
int largest = 0;
int tmp;
void Max_heapify(int i)
{
	int L = 2 * i;
	int R = 2 * i + 1;

	if (L<=sizeof(heap)/4 &&heap[L] > heap[i])
		largest = L;
		else largest = i;
	if (R <= sizeof(heap)/4 && heap[R] > heap[largest])
		largest = R;
	if (largest != i)
	{
		tmp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = tmp;
		Max_heapify(largest);
	}
}
int main()
{
	Max_heapify(2);

	for (int i = 1; i < sizeof(heap) / 4; i++)
	{
		printf("heap[%d] = %d\n", i, heap[i]);
	}
}