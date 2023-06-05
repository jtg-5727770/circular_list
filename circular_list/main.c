#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ���
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return NULL;
	}
	ListNode* removed = head->link;

	if (head->link == head)
	{
		printf("ù��° ��尡 �����Ǿ����ϴ�.\n");
		free(head);
		return NULL;
		
	}
	head->link = removed->link;
	free(removed);
	printf("ù��° ��尡 �����Ǿ����ϴ�.\n");
	return head;
}

ListNode* delete_last(ListNode* head)
{
	if (head == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return NULL;
	}

	if (head->link == head) { 
		printf("������ ��尡 �����Ǿ����ϴ�.\n");
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
	printf("������ ��尡 �����Ǿ����ϴ�.\n");
	return head;
}


int main(void) {
	ListNode* head = NULL;
	int n;
	int value;
	while (1) {

		printf("=========�޴�=========\n");
		printf("1.���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2.���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3.����Ʈ ó�� ��� ����\n");
		printf("4.����Ʈ ������ ��� ����\n");
		printf("5.����\n");
		printf("��ȣ�� �����ϼ���: ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			printf("���ڸ� �Է��ϼ���: ");
			scanf_s("%d", &value);
			head = insert_first(head, value);
			print_list(head);
			
			break;
		case 2:
			printf("���ڸ� �Է��ϼ���: ");
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
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
		default:
			printf("�ٽ� �������ּ���.\n");
			while (getchar() != '\n');
		}
	}
	system("pause");
	return 0;
}
