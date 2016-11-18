parent(bob, fred).
parent(bob, sally).
parent(fred, arthur).
parent(sally, matilda).

sibling(ChildX, ChildY) :- parent(ParentA, ChildX), parent(ParentA, ChildY).
cousin(CousinX, CousinY) :- parent(ParentA, CousinX), parent(ParentB, CousinY), sibling(ParentA, ParentB), ParentA \= ParentB.
