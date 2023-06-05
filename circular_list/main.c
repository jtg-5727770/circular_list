#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return NULL;
	}
	ListNode* removed = head->link;

	if (head->link == head)
	{
		printf("첫번째 노드가 삭제되었습니다.\n");
		free(head);
		return NULL;
		
	}
	head->link = removed->link;
	free(removed);
	printf("첫번째 노드가 삭제되었습니다.\n");
	return head;
}

ListNode* delete_last(ListNode* head)
{
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return NULL;
	}

	if (head->link == head) { 
		printf("마지막 노드가 삭제되었습니다.\n");
		free(head);
		return NULL;
	}	

	ListNode* p1 = head;
	ListNode* p2 = p1->link;
	while (p2 != head) {
		p1 = p2;
		p2 = p2->link;
	}
	p1->link = head->link;
	head = p1;
	free(p2);
	printf("마지막 노드가 삭제되었습니다.\n");
	return head;
}


int main(void) {
	ListNode* head = NULL;
	int n;
	int value;
	while (1) {

		printf("=========메뉴=========\n");
		printf("1.숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2.숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3.리스트 처음 노드 삭제\n");
		printf("4.리스트 마지막 노드 삭제\n");
		printf("5.종료\n");
		printf("번호를 선택하세요: ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			printf("숫자를 입력하세요: ");
			scanf_s("%d", &value);
			head = insert_first(head, value);
			print_list(head);
			
			break;
		case 2:
			printf("숫자를 입력하세요: ");
			scanf_s("%d", &value);
			head = insert_last(head, value);
			print_list(head);
			break;
		case 3:
			head = delete_first(head);
			print_list(head);
			break;
		case 4:
			head = delete_last(head);
			print_list(head);
			
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("다시 선택해주세요.\n");
			while (getchar() != '\n');
		}
	}
	system("pause");
	return 0;
}
