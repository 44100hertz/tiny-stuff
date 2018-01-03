struct Pizza {
	int pep;
	int poop;
};

Pizza cheese() {
	return (Pizza){
		.pep = 0,
				.poop = 1,
	};
}
