#include <stdio.h>

#define N 1000
int arr[N];

/* �Գ���Ϊn������arrִ��ѡ������ */
void selectionSort(int arr[], int n);

/* ��ӡ����Ϊn������arr */
void printArray(int arr[], int n);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
/* ��ӡ����Ϊn������arr */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)  /* �±�0..n-2ÿ��Ԫ�غ����и��ո� */
            printf(" ");/*�±�n-1,Ҳ�������һ��Ԫ�غ���û�пո�*/
    }
    printf("\n");/* һ�д�ӡ����� */
}

/* ��Ĵ��뽫Ƕ������ */
void selectionSort(int arr[], int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
	swap(&arr[i],&arr[min]);
	}
 } 
