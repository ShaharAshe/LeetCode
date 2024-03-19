#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result_node = NULL,
                    *temp_result = NULL,
                    *temp_l1 = l1,
                    *temp_l2 = l2;;
    size_t sum = 0;
    
    while(temp_l1 || temp_l2 || sum) {
        if(temp_l1){
            sum += temp_l1->val;
            temp_l1 = temp_l1->next;
        }
        if(temp_l2){
            sum += temp_l2->val;
            temp_l2 = temp_l2->next;
        }
        if (!result_node) {
            result_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp_result = result_node;
            temp_result->next = NULL;
            temp_result->val = sum%10;
            sum /= 10;
        } else {
            temp_result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp_result = temp_result->next;
            temp_result->next = NULL;
            temp_result->val = sum%10;
            sum /= 10;
        }
    }
    temp_result = NULL;
    temp_l1 = NULL;
    temp_l2 = NULL;

    return result_node;
}

void freeNode(struct ListNode* node){
    while (node)
    {
        struct ListNode *fast_l1 = node->next;
        
        if(fast_l1 && fast_l1->next){
            node->next = NULL;
            free(node);

            node = fast_l1;
            fast_l1 = fast_l1->next;
        }
        else if (!fast_l1->next){
            free(node);
            node = NULL;
        }
    }
}


int main(){
    struct ListNode* result = NULL,
                    *temp_result = NULL;
    // l1 = [2,4,3], l2 = [5,6,4]
    // struct ListNode *node_l1 = NULL,
    //                 *node_l2 = NULL;
    // node_l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l1->val = 2;
    // node_l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l1->next->val = 4;
    // node_l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l1->next->next->val = 3;
    // node_l1->next->next->next = NULL;
    //
    // node_l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l2->val = 5;
    // node_l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l2->next->val = 6;
    // node_l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    // node_l2->next->next->val = 4;
    // node_l2->next->next->next = NULL;

    // l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    struct ListNode *node_l1 = NULL,
                    *node_l2 = NULL;
    node_l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->val = 9;
    node_l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->val = 9;
    node_l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->next->val = 9;
    node_l1->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->next->next->val = 9;
    node_l1->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->next->next->next->val = 9;
    node_l1->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->next->next->next->next->val = 9;
    node_l1->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l1->next->next->next->next->next->next->val = 9;
    node_l1->next->next->next->next->next->next = NULL;

    node_l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l2->val = 9;
    node_l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l2->next->val = 9;
    node_l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l2->next->next->val = 9;
    node_l2->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    node_l2->next->next->next->val = 9;
    node_l2->next->next->next->next = NULL;

    result = addTwoNumbers(node_l1, node_l2),
    temp_result = result;
    while (temp_result)
    {
        printf(", %d", temp_result->val);
        temp_result = temp_result->next;
    }
    
    freeNode(node_l1);
    freeNode(node_l2);
    freeNode(result);
    node_l1 = NULL;
    node_l2 = NULL;
    result = NULL;
    temp_result = NULL;
    
    return 0;
}