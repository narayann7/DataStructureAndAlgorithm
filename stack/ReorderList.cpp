//leetcode
//143. Reorder List

class Solution {
public:
	void reorderList(ListNode* head) {


		ListNode* temp=head;
		int count=0;
		while(temp){
			count++;
			temp=temp->next;    
		}
		temp=head;

		int half=0;

		if(count%2==0)
			half=count/2;
		else
			half=(count/2) + 1;

		count=0;

		while(count!=half-1){
			temp=temp->next;
			count++;
		}

		stack< ListNode*> stack;

		while(temp->next){
			temp=temp->next;
			stack.push(temp);
		}

		temp=head;
		ListNode* temp2;
		while(!stack.empty())
		{
			temp2=temp->next;
			temp->next=stack.top();
			stack.pop();
			temp->next->next=temp2;
			temp=temp2;

		}
		temp->next=NULL;

	}
};