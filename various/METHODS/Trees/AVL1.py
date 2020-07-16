import logging

# Init Logging Facilities
log = logging.getLogger(__name__)


class Node:
    """Self-balancing Binary Search Tree node.
    This Binary Tree implementation balances on each insert.
    If performance is of concern to you, implementing a bulk-balance
    method may be of interest (c-based implementations aside).
    Attributes:
        value: value of the Node
        parent: Parent node of this Node
        is_root: Boolean, to determine if this Node is root
        left_child: Left child of this Node; Values smaller than price
        right_child: Right child of this Node; Values greater than price
    Properties:
        height: Height of this Node
        balance: Balance factor of this Node
    """
    __slots__ = ['value', 'is_root', 'parent', 'left_child', 'right_child']

    def __init__(self, value, root=False):
        """Initialize a Node() instance.
        :param value:
        :param root:
        """
        self.value = value if not root else None
        self.is_root = root
        self.parent = None
        self.left_child = None
        self.right_child = None

    @property
    def balance(self):
        """Calculate and return the balance of this Node.
        Calculate balance by dividing the right child's height from
        the left child's height. Children which evaluate to False (None)
        are treated as zeros.
        :return:
        """
        right_height = self.right_child.height if self.right_child else 0
        left_height = self.left_child.height if self.left_child else 0

        return right_height - left_height

    @property
    def grandpa(self):
        if self.parent:
            return self.parent.parent
        else:
            return None

    @property
    def height(self):
        """Calculate the height of the tree up to this Node.
        :return: int, max height among children.
        """
        left_height = self.left_child.height if self.left_child else 0
        right_height = self.right_child.height if self.right_child else 0
        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def insert(self, value):
        """Recursive AVL Insert method to insert a new Node.
        Inserts a new node and calls the grand-parent's balance() method -
        but only if it isn't root.
        :param value:
        :return:
        """
        if self.value is None or value > self.value:
            if self.right_child is None:
                self.right_child = Node(value, root=False)
                self.right_child.parent = self
                self.right_child.balance_grandpa()
            else:
                self.right_child.insert(value)
        elif value < self.value:
            if self.left_child is None:
                self.left_child = Node(value, root=False)
                self.left_child.parent = self
                self.left_child.balance_grandpa()
            else:
                self.left_child.insert(value)

    def balance_grandpa(self):
        """Check if our grandparent needs rebalancing.
        :return:
        """
        if self.grandpa and self.grandpa.is_root:
            # If our grandpa is root, we do nothing.
            pass
        elif self.grandpa and not self.grandpa.is_root:
            # Check the balance.
            self.grandpa._balance()
        elif self.grandpa is None:
            # We don't have a grandpa!
            pass
        else:
            # Unforeseen things have happened. D:
            raise NotImplementedError
        return

    def _balance(self):
        """Call the rotation method relevant to this Node's balance.
        :return:
        """
        if self.balance > 1:
            # right is heavier 
            if self.right_child.balance < 0:
                # right_child.left is heavier, RL case
                self._rl_case()
            elif self.right_child.balance > 0:
                # right_child.right is heavier, RR case
                self._rr_case()
        elif self.balance < -1:
            # left is heavier 
            if self.left_child.balance < 0:
                # left_child.left is heavier, LL case
                self._ll_case()
            elif self.left_child.balance > 0:
                # left_child.right is heavier, LR case
                self._lr_case()

    def _ll_case(self):
        """Rotate Nodes for LL Case.
        Reference:
            https://en.wikipedia.org/wiki/File:Tree_Rebalancing.gif
        :return:
        """
        child = self.left_child

        if self.parent.is_root or self.value > self.parent.value:
            self.parent.right_child = child
        else:
            self.parent.left_child = child

        child.parent, self.parent = self.parent, child
        child.right_child, self.left_child = self, child.right_child

    def _rr_case(self):
        """Rotate Nodes for RR Case.
        Reference:
            https://en.wikipedia.org/wiki/File:Tree_Rebalancing.gif
        :return:
        """
        child = self.right_child

        if self.parent.is_root or self.value > self.parent.value:
            self.parent.right_child = child
        else:
            self.parent.left_child = child

        child.parent, self.parent = self.parent, child
        child.left_child, self.right_child = self, child.left_child

    def _lr_case(self):
        """Rotate Nodes for LR Case.
        Reference:
            https://en.wikipedia.org/wiki/File:Tree_Rebalancing.gif
        :return:
        """
        child, grand_child = self.left_child, self.left_child.right_child
        child.parent, grand_child.parent = grand_child, self
        child.right_child = grand_child.left_child
        self.left_child, grand_child.left_child = grand_child, child
        self._ll_case()

    def _rl_case(self):
        """Rotate Nodes for RL case.
        Reference:
            https://en.wikipedia.org/wiki/File:Tree_Rebalancing.gif
        :return:
        """
        child, grand_child = self.right_child, self.right_child.left_child
        child.parent, grand_child.parent = grand_child, self
        child.left_child = grand_child.right_child
        self.right_child, grand_child.right_child = grand_child, child
        self._rr_case()

    def __str__(self):
        if not self.is_root:
            s = 'Node Value: %s\n' % self.value
            s += 'Node left_child value: %s\n' % (self.left_child.value if self.left_child else 'None')
            s += 'Node right_child value: %s\n\n' % (self.right_child.value if self.right_child else 'None')
        else:
            s = ''

        left_side_print = self.left_child.__str__() if self.left_child else ''
        right_side_print = self.right_child.__str__() if self.right_child else ''
        return s + left_side_print + right_side_print


class BST(Node):
    def __init__(self):
        super(BST, self).__init__(None, root=True)

if __name__ == '__main__':
    print("Testing Left Left Case")
    values = [5, 3, 2]
    print("Input", values)
    root = BST()
    for v in values:
        root.insert(v)

    print(root.right_child.balance)
    print(root)
    print("----------")

    print("Testing Right Right Case")
    values = [3, 5, 7]
    print("Input", values)
    root = BST()
    for v in values:
        root.insert(v)

    print(root.right_child.balance)
    print(root)
    print("----------")

    print("Testing Left Right Case")
    values = [5, 3, 4]
    print("Input", values)
    root = BST()
    for v in values:
        root.insert(v)

    print(root.right_child.balance)
    print(root)
    print("----------")

    print("Testing Right Left Case")
    values = [3, 5, 4]
    print("Input", values)
    root = BST()
    for v in values:
        root.insert(v)

    print(root.right_child.balance)
    print(root)
    print("----------")