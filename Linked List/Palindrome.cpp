/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT


*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* reverse(node* head){
	if (head == NULL || head->next == NULL) 
            return head; 
  
    /* reverse the rest list and put  
      the first element at the end */
    node* rest = reverse(head->next); 
    head->next->next = head; 

    /* tricky step -- see the diagram */
    head->next = NULL; 

    /* fix the head pointer */
    return rest; 
	// return newhead;
}

bool check_palindrome(node* head){
	int length = 0;
	node* start = head;
	while(start!=NULL){
		length++;
		start = start->next;
	}

	start = head;
	int temp = (length+1)/2;	


	//Reverse the mid part
	node* second = head;

	for (int i = 0; i < temp; ++i)
	{
		second=second->next;
	}

	node* second_head = reverse(second);
	
	// cout << second_head->data << '\n';
	// return 0;

	temp = length/2;
	second = second_head;
	// cout << start->data << '\n';
	// return 0;

	while(second!=NULL){
		if (start->data != second->data)
		{
			return 0;
		}

		second = second->next;
		start = start->next;
	}



	return 1;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";

	return 0 ;

}

