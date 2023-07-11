%insert_list(L: list, List: list, R: list)
%flow model: (i, i, o)

insert_list([], L, L).
insert_list([H|T], L, [H|R]):- 
    insert_list(T, L, R).

%substitute_elem(L:list, E:number, List:list, R:list)
%flow model: (i, i, i, o)

substitute_elem([], _, _, []).

substitute_elem([H|T], E, List, R) :- 
    H =:= E,
    insert_list(List, T, RI),
    substitute_elem(RI, E, List, R).

substitute_elem([H|T], E, List, [H|R]) :- 
    H =\= E,
    substitute_elem(T, E, List, R).

%substitute_elem([1,2,3,2,3,5],3,[0,1],R).