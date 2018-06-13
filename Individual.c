struct Individual
{
	int phenotype;
	char genome;
	float score;
};

struct Individual createIndividual(int pPhenotype)
{
	struct Individual indiv;
	indiv.phenotype = pPhenotype;
	return indiv;
}


















































