
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


// ��ʼ���ڵ��ӵ����
#define	listSET_LIST_ITEM_OWNER( pxListItem, pxOwner ) \
		( ( pxListItem )->pvOwner = ( void * ) (pxOwner) )
				
// ��ȡ�ڵ�ӵ����
#define	listGET_LIST_ITEM_OWNER( pxListItem ) \
		( ( pxListItem )->pvOwner )
		
// ��ʼ���ڵ�������ֵ
#define	listSET_LIST_ITEM_VALUE( pxListItem, xValue ) \
		( ( pxListItem )->xItemValue = ( xValue ) )
		
// ��ȡ�ڵ�������ֵ
#define	listGET_LIST_ITEM_VALUE( pxListItem ) \
		( ( pxListItem )->xItemValue )
		
// ��ȡ������ڵ�Ľڵ��������ֵ
#define	listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxList ) \
		( ( ( pxList )->xListEnd ).pxNext->xItemValue )
		
// ��ȡ�������ڽڵ�
#define	listGET_HEAD_ENTRY( pxList ) \
		( ( ( pxList )->xListEnd ).pxNext )
		
// ��ȡ�ڵ����һ���ڵ�
#define	listGET_NEXT( pxListItem ) \
		( ( pxListItem )->pxNext )
		
// ��ȡ��������һ���ڵ�
#define	listGET_END_MARKER( pxList ) \
		( ( ListItem_t const * ) ( &( ( pxList )->xListEnd ) ) )
			
// �ж������Ƿ�Ϊ��
#define	listLIST_IS_EMPTY( pxList ) \
		( ( BaseType_t ) ( ( pxList )->uxNumberOfItems == ( UBaseType_t ) 0 ) )

// ��ȡ����Ľڵ���
#define	listCURRENT_LIST_LENGTH( pxList ) \
		( ( pxList )->uxNumberOfItems )
		
// ��ȡ�����һ���ڵ��OWNER����TCB
#define	listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList ) 	\
{	\
}	\


