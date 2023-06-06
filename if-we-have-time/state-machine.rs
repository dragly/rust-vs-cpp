
fn has_rhs_xyes(horizon: &[u8]) -> bool {
	#[derive(Clone)]
	#[derive(Copy)]
	enum Lex {
		Start,
		FirstSpace,
		Negation,
		FirstEq,
		SecondEq,
		SecondSpace,
	}
	let mut state = Lex::Start;

	for byte in horizon {
		match (state, byte) {
			(Lex::Start, b' ') => state = Lex::FirstSpace,
			(Lex::FirstSpace, b'=') => state = Lex::FirstEq,
			(Lex::FirstSpace, b'!') => state = Lex::Negation,
			(Lex::Negation, b'=') => state = Lex::SecondEq,
			(Lex::FirstEq, b'=') => state = Lex::SecondEq,
			(Lex::FirstEq, b' ') => state = Lex::SecondSpace,
			(Lex::SecondEq, b' ') => state = Lex::SecondSpace,
			(Lex::SecondSpace, b'x') => return true,
			(_, _) => break,
		}
	}
	false
}
