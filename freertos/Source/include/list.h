
#include "portmacro.h"

// ����ڵ�ṹ��
struct xLIST_ITEM
{

	TickType_t xItemValue;			// ����ֵ�����ڰ����ڵ���˳������
	struct xLIST_ITEM * pxNext;		// ָ��������һ���ڵ�
	struct xLIST_ITEM * pxPrevious;	// ָ������ǰһ���ڵ�
	void * pvOwner;					// ָ��ӵ�иýڵ���ں˶���ͨ����TCB
	void * pvContainer;				// ָ��ýڵ���������

};
typedef struct xLIST_ITEM ListItem_t;	// �ڵ����������ض���


// ����Ľڵ�ṹ��
struct xMINI_LIST_ITEM
{

	TickType_t xItemValue;			// ����ֵ�����ڰ����ڵ�����������
	struct xLIST_ITEM * pxNext;		// ָ��������һ���ڵ�
	struct xLIST_ITEM * pxPrevious;	// ָ������ǰһ���ڵ�
	
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;


// ����ṹ��
typedef struct xLIST
{

	UBaseType_t uxNumberOfItems;	// ����ڵ�����������ڱ�ʾ���������ж��ٸ��ڵ㣬���ڵ����
	ListItem_t * pxIndex;			// ����ڵ�����ָ�룬���ڱ����ڵ�
	MiniListItem_t xListEnd;		// �������һ���ڵ㣬��Ϊ��������β�����ģ�����Ҳ�ǵ�һ���ڵ㣬��֮Ϊ������

} List_t;




