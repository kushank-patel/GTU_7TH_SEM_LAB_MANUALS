from pythonds.basic.stack import Stack
from pythonds.trees.binaryTree import BinaryTree


def buildParseTree(fpexp):
    fplist = fpexp.split()
    pStack = Stack()
    eTree = BinaryTree('')
    pStack.push(eTree)
    currentTree = eTree

    for i in fplist:
        if i == '(':  # adds a new node as the left child of the current node, and descend to the left child
            currentTree.insertLeft('')
            pStack.push(currentTree)
            currentTree = currentTree.getLeftChild()

        elif i in ['+', '-', '*', '/']:
            # adds a new node as the right child of the current node, and descend to the left child
            currentTree.setRootVal(i)
            currentTree.insertRight('')
            pStack.push(currentTree)
            currentTree = currentTree.getRightChild()

        elif i == ')':
            currentTree = pStack.pop()

        # sets root value of the current node to the operator represented by the current token or number.
        elif i not in ['+', '-', '*', '/', ')']:
            try:
                currentTree.setRootVal(int(i))
                parent = pStack.pop()
                currentTree = parent

            except ValueError:
                raise ValueError("token '{}' is not a valid integer".format(i))

    return eTree


def main():
    pt = buildParseTree("( ( 10 + 5 ) * 3 )")
    pt.postorder()  # defined and explained in the next section


main()
