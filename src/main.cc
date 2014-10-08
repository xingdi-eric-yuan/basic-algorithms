
#include "general_settings.h"
using namespace std;

int main(){

/*
    unordered_map<string, double> graph_distance;
    GraphNode a(0, 0, INT_MAX, 4);
    GraphNode b(1, 1, INT_MAX, 2);
    GraphNode c(2, 2, INT_MAX, 4);
    GraphNode d(3, 3, INT_MAX, 4.5);
    GraphNode e(4, 4, INT_MAX, 2);
    GraphNode f(5, 5, INT_MAX, INT_MAX);
    GraphNode g(6, 6, INT_MAX, INT_MAX);

    concatenate(&f, &a, graph_distance, 1.5);
    concatenate(&a, &b, graph_distance, 2);
    concatenate(&b, &c, graph_distance, 3);
    concatenate(&c, &g, graph_distance, 4);
    concatenate(&f, &d, graph_distance, 2);
    concatenate(&d, &e, graph_distance, 3);
    concatenate(&e, &g, graph_distance, 2);
    //double dis = getDijkstraDistance(&a, &e, graph_distance);
    //cout<<"dis = "<<dis<<endl;
    //printGraphDFS(&a);
    A_star(&f, &g, graph_distance);
    graph_distance.clear();
*/

/*
    vector<ListNode*> vec(10);
    for(int i = 0; i < vec.size(); i++){
    	vec[i] = new ListNode((double)i);
    }
    random_shuffle(vec.begin(), vec.end());
    for(int i = 0; i < vec.size() - 1; i++){
    	vec[i] -> next = vec[i + 1];
    }
    ListNode *head = vec[0];
    printLinkedList(head);
    head = reverseLinkedList(head);
    printLinkedList(head);
*/

/*
    vector<double> vec(100, 0.0);
    for(int i = 0; i < vec.size(); i++){
    	vec[i] = (double)i;
    }
    random_shuffle(vec.begin(), vec.end());
	printArray(vec);

    quickSort(vec, 0, vec.size() - 1);
    printArray(vec);

    random_shuffle(vec.begin(), vec.end());
	mergeSort(vec, 0, vec.size() - 1);
    printArray(vec);
*/
    vector<GraphNode*> vec;
    GraphNode a(0, 0, INT_MAX, 4);
    GraphNode b(1, 1, INT_MAX, 2);
    GraphNode c(2, 2, INT_MAX, 4);
    GraphNode d(3, 3, INT_MAX, 4.5);
    GraphNode e(4, 4, INT_MAX, 2);
    GraphNode f(5, 5, INT_MAX, INT_MAX);
    GraphNode g(6, 6, INT_MAX, INT_MAX);
    vec.push_back(&a);
    vec.push_back(&b);
    vec.push_back(&c);
    vec.push_back(&d);
    vec.push_back(&e);
    vec.push_back(&f);
    vec.push_back(&g);

	BinaryTreeNode *root = createBinaryTree(vec, 0, vec.size() - 1);
	printTree(root);

	BinaryTreeNode *succ = predecessor(root -> left -> left);
	if(succ) cout<<succ -> graphnode -> id<<endl;
	else cout<<"NULL"<<endl;

	return 0;
}







