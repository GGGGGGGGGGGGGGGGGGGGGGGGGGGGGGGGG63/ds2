#include <stdio.h>

#define MAXTABLESIZE 100000  /* �����ٵ����ɢ�б��� */
typedef int ElementType;     /* �ؼ������������� */
typedef int Index;           /* ɢ�е�ַ���� */
typedef Index Position;      /* ��������λ����ɢ�е�ַ��ͬһ���� */
/* ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ�� */
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell; /* ɢ�б�Ԫ���� */
struct HashEntry{
    ElementType Data; /* ���Ԫ�� */
    EntryType Info;   /* ��Ԫ״̬ */
};

typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
    int TableSize; /* �����󳤶� */
    Cell *Cells;   /* ���ɢ�е�Ԫ���ݵ����� */
};

HashTable BuildTable(); /* ����ʵ�֣�ϸ�ڲ��� */
Position Hash( ElementType Key, int TableSize )
{
    return (Key % TableSize);
}

#define ERROR -1
Position Find( HashTable H, ElementType Key );

int main()
{
    HashTable H;
    ElementType Key;
    Position P;

    H = BuildTable(); 
    scanf("%d", &Key);
    P = Find(H, Key);
    if (P==ERROR)
        printf("ERROR: %d is not found and the table is full.\n", Key);
    else if (H->Cells[P].Info == Legitimate)
        printf("%d is at position %d.\n", Key, P);
    else
        printf("%d is not found.  Position %d is returned.\n", Key, P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Position Find( HashTable H, ElementType Key ){
	Position p0,p;
	int Cnum=0;//��ͻ��
	p=p0=Hash(Key,H->TableSize);
	while(H->Cells[p].Info!=Empty&&H->Cells[p].Data!=Key){
		Cnum++;
		if(Cnum==MAXTABLESIZE){
			return ERROR;
		}
		p=(p0+Cnum)%H->TableSize;		
	}
	return p;
}

