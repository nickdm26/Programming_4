swimmer(anne).
swimmer(david).
swimmer(ellen).
cyclist(anne).
cyclist(bob).
cyclist(carl).
runner(bob).
runner(ellen).
runner(fred).

team(Swim, Cycle, Run) :- swimmer(Swim), cyclist(Cycle), runner(Run), Swim \= Cycle, Swim \= Run, Cycle \= Run.