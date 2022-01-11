template<class T>
class RBTTreeNode {
	T data;
	RBTTreeNode<T>* parent;
	RBTTreeNode<T>* left;
	RBTTreeNode<T>* right;
	int color;
public:
};

template<class T>
class RBTTree {
	RBTTreeNode<T>* root;
public:
	void insert() {}
	RBTTreeNode<T>* begin() {}
	void remove() {}
	bool isEmpoty() {}
};

template <class T>
class PriorityQueue {
	RBTTree<T> tree;
public:
	PriorityQueue() :tree(nullptr) {}
	void enqueue(T item) { tree.insert(item) }
	T dequeur() {
		if (tree.isEmpoty()) {
			return NULL;
		}
		else {
			RBTTreeNode<T>* toDelete = tree.begin();
			T temp = toDelete->data;
			tree.remove(toDelete);
			return temp;
		}
	}
	T top() {
		if (tree.isEmpoty()) {
			return NULL;
		}
		else {
			RBTTreeNode<T>* toDelete = tree.begin();
			T temp = toDelete->data;
			return temp;
		}
	}
};