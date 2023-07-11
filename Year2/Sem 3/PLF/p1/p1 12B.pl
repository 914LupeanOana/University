%remove_nth(L: list, K: number, R: list)
%flow model: (i, i, o)

remove_nth([], _, []).
remove_nth([_|T], 1, T).
remove_nth([H|T], K, [H|R]) :-
    K1 is K - 1,
    remove_nth(T, K1, R).

%remove_nth([1,2,3,4,5,6,7,8],4,A).