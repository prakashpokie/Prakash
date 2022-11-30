#include<stdio.h>
#include<stdlib.h>

struct link
{
int coeff;
int pow;
struct link * next;
};
void create(struct link **);
void show(struct link *);
void add(struct link **, struct link *, struct link *);
int main(void)
{
int ch;
do
{
struct link * poly1, * poly2, * poly3;
printf("\n1st expression");
create(&poly1);
show(poly1);
printf("\n2nd expression");
create(&poly2);
show(poly2);
add(&poly3, poly1, poly2);
show(poly3);
printf("\nAdd two more expression? (1/0): ");
scanf("%d", &ch);
}
while (ch);
return 0;
}
void create(struct link ** node)
{
int flag;
int coeff, pow;
struct link * tmp_node;
tmp_node = (struct link *) malloc(sizeof(struct link));
*node = tmp_node;
do
{
printf("Coefficient term:");
scanf("%d", &coeff);
tmp_node->coeff = coeff;
printf("Power term:");
scanf("%d", &pow);
tmp_node->pow = pow;
tmp_node->next = NULL;
printf("\nContinue Adding terms(1/0): ");
scanf("%d", &flag);
if(flag)
{
tmp_node->next = (struct link *) malloc(sizeof(struct link));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
} while (flag);
}
void show(struct link * node)
{
printf("\nThe polynomial expression is:");
while(node != NULL)
{
printf("%dx^%d", node->coeff, node->pow);
node = node->next;
if(node != NULL && node->coeff >= 0)
printf("+");
}
}
void add(struct link ** result, struct link * poly1, struct link * poly2)
{
struct link * tmp_node;
tmp_node = (struct link *) malloc(sizeof(struct link));
tmp_node->next = NULL;
*result = tmp_node;
while(poly1 && poly2)
{
if (poly1->pow > poly2->pow)
{
tmp_node->pow = poly1->pow;
tmp_node->coeff = poly1->coeff;
poly1 = poly1->next;
}
else if (poly1->pow < poly2->pow)
{
tmp_node->pow = poly2->pow;
tmp_node->coeff = poly2->coeff;
poly2 = poly2->next;
}
else
{
tmp_node->pow = poly1->pow;
tmp_node->coeff = poly1->coeff + poly2->coeff;
poly1 = poly1->next;
poly2 = poly2->next;
}
if(poly1 && poly2)
{
tmp_node->next = (struct link *) malloc(sizeof(struct link));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
}
}
while(poly1 || poly2)
{
tmp_node->next = (struct link *) malloc(sizeof(struct link));
tmp_node = tmp_node->next;
tmp_node->next = NULL;
if(poly1)
{
tmp_node->pow = poly1->pow;
tmp_node->coeff = poly1->coeff;
poly1 = poly1->next;
}
if(poly2)
{
tmp_node->pow = poly2->pow;
tmp_node->coeff = poly2->coeff;
poly2 = poly2->next;
}
}
printf("\n Final expression");
}
