
#include "portmacro.h"

// 链表节点结构体
struct xLIST_ITEM
{

	TickType_t xItemValue;			// 辅助值，用于帮助节点做顺序排列
	struct xLIST_ITEM * pxNext;		// 指向链表下一个节点
	struct xLIST_ITEM * pxPrevious;	// 指向链表前一个节点
	void * pvOwner;					// 指向拥有该节点的内核对象，通常是TCB
	void * pvContainer;				// 指向该节点所在链表

};
typedef struct xLIST_ITEM ListItem_t;	// 节点数据类型重定义


// 精简的节点结构体
struct xMINI_LIST_ITEM
{

	TickType_t xItemValue;			// 辅助值，用于帮助节点做升序排列
	struct xLIST_ITEM * pxNext;		// 指向链表下一个节点
	struct xLIST_ITEM * pxPrevious;	// 指向链表前一个节点
	
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;


// 链表结构体
typedef struct xLIST
{

	UBaseType_t uxNumberOfItems;	// 链表节点计数器，用于表示该链表下有多少个节点，根节点除外
	ListItem_t * pxIndex;			// 链表节点索引指针，用于遍历节点
	MiniListItem_t xListEnd;		// 链表最后一个节点，因为链表是首尾相连的，所以也是第一个节点，称之为生产者

} List_t;




