# Floyed Loop

# Double linked List definition
class DListNode(object):
    def __init__(self):
        # self.value = x
        self.next = None
        self.prev = None

class Floyed(object):
    def __init__(self):
        self.head = None
        # super(Floyed, self).__init__()
        self.slow = DListNode()
        self.fast = DListNode()
        self.slow = self.head
        self.fast = self.head

    def isLoop( self):
        loopExist = False
        # fast node is 2 steps ahead
        while self.slow.next and self.fast.next.next:
            self.slow = self.slow.next
            self.fast = self.fast.next.next
            if self.low == self.fast:
                loopExist = True
                break
            if self.fast.next == self.head:
                break
        return loopExist

    def findLoopHead(self):
        if self.isLoop():
            self.slow = self.head
            while self.slow != self.fast:
                self.slow = self.slow.next
                self.fast = self.fast.next
            # return Loop head
            return self.slow
        else:
            return print('No loop exists!')
            