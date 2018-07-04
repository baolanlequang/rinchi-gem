#include <iostream>

#include "rinchi_reaction.h"
#include "mdl_molfile_reader.h"
#include "rinchi.h"

void add_components(rinchi::Reaction& rxn, rinchi::ReactionComponent* rc, MolVect& comps, int comp_type) {	
	if (!comps.empty()) {
		rinchi::MdlMolfileReader mol_reader;

		for(MolVect::iterator it = comps.begin(); it != comps.end(); ++it) {
			switch (comp_type) {
				case 1:
					rc = rxn.add_reactant();
					break;
				case 2:
					rc = rxn.add_product();
					break;
				case 3:
					rc = rxn.add_agent();
					break;
			}
			std::istringstream comp(*it);
			mol_reader.read_molecule(comp, *rc);
		}	
	}
}

void insert_results(rinchi::Reaction& rxn, MolVect& results) {
	results.push_back(rxn.rinchi_string());
	results.push_back(rxn.rinchi_long_key());
	results.push_back(rxn.rinchi_short_key());
	results.push_back(rxn.rinchi_web_key());
}

MolVect convert(MolVect& rcts, MolVect& prds, MolVect& agts) {
	MolVect results;

	try {
		rinchi::Reaction rxn;
		rinchi::ReactionComponent* rc;

		// Load reactant(s).
		add_components(rxn, rc, rcts, 1);
		// Load product(s).
		add_components(rxn, rc, prds, 2);
		// Load agent(s).
		add_components(rxn, rc, agts, 3);

		insert_results(rxn, results);
	} catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return results;
}
