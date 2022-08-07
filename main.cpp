
// #include "data-structures/graph.h"

#include "data-structures/binaryTree.h"


int main() {

	BST tree1;

	int input = 0, choice = 0;

	std::cout << "Enter an integer for the root node : ";
	std::cin >> input;

	tree1.hook = tree1.createNewNode(input);

	/*
	* choice 1 = create new Node
	* choice 2 = search
	* choice 3 = breadth first search
	* choice 4 = depth first search inorder
	* choice 5 = depth first search postorder
	* choice 6 = depth first search preorder
	* choice 7 = check if tree is binary search tree or not
	* choice 8 = delete node
	* choice 9 = exit
	* 
	*/

	while (choice != 9) {

		std::cout << "Enter a choice: \n choice 1 = create new Node \n choice 2 = search \n choice 3 = breadth first search" << std::endl;
		
		std::cout << " choice 4 = depth first search inorder \n choice 5 = depth first search postorder \n choice 6 = depth first search preorder " << std::endl;
		
		std::cout << " choice 7 = check if tree is binary search tree or not \n choice 8 = delete node \n choice 9 = exit" << std::endl;
			 
		std::cin >> choice;

		switch (choice) {
			case 1:
				std::cout << "Enter an integer for the node : ";
				std::cin >> input;

				tree1.hook = tree1.insert(tree1.hook, input);
				break;

			case 2:
				std::cout << "Enter an integer to search for : ";
				std::cin >> input;

				tree1.hook = tree1.search(tree1.hook, input);
				break;

			case 3:
				tree1.BFT(tree1.hook);
				break;

			case 4:
				tree1.DFT_inorder(tree1.hook);
				break;

			case 5:
				tree1.DFT_postorder(tree1.hook);
				break;

			case 6:
				tree1.DFT_preorder(tree1.hook);
				break;

			case 7:
				if (tree1.isBST(tree1.hook) == true) {
					std::cout << "It is a Binary Search Tree." << std::endl;
				}
				else {
					std::cout << "It is not a Binary Search Tree." << std::endl;
				}
				break;

			case 8:
				std::cout << "Enter an integer to be deleted : ";
				std::cin >> input;

				tree1.hook = tree1.deleteNode(tree1.hook, input);
				break;

			case 9:
				return 0;

			default:
				std::cout << "EEnter a correct option" << std::endl;
		}
			 
	}



	/*
	int beginningNode = 0;


	graph SampleGraph;

	std::cout << "Enter a node to begin Depth First Search with : ";
	std::cin >> beginningNode;

	SampleGraph.DFT(beginningNode);

	// std::cout << "Enter a node to begin Breadth First Search with : ";
	// std::cin >> beginningNode;

	// SampleGraph.BFT(beginningNode);
	*/
	return 0;
}





