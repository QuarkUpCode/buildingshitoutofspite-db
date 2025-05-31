jaaaj = {
    "Joueur" : ["_ID_", "Nom d'utilisateur", "Niveau", "XP", "Or"],
    "Personnage" : ["_PID_", "CID", "Nom", "Force", "Agilité", "Intelligence", "Vie", "Mana", "Classe", "Niveau?"],
    "Inventaire" : ["_CID_", "Capacité"],
    "ObjetEnCirculation" : ["_Nom d'objet_", "_CID_", "_Quantitée_"],
    "ObjetÉquipé" : ["_Instance D'ObjetEnCirculation_", "_Emplacement_"],
    "Objet" : ["_Nom_", "Prix", "Puissance d'attaque", "Défense", "Soins"], #Vu que le nombre de fields spécifique au type d'objet est faible et constant on peut simplement laisser par example le field Soins à 0 si c'est une Arme
    "EffetObjet" : ["_Nom d'objet_", "_Effet_"],
    
    "Sort" : ["_Nom_", "Coût en mana", "Temps de recharge", "Puissance d'attaque"],
    "SortParPersonnage" : ["_Nom du Sort_", "_CID_"],

    "Quête" : ["_Nom_", "Description", "Difficulté"],
    "Récompense" : ["_Nom de la Quête_", "Or", "XP"],
    "QuêteParPersonnage" : ["_Nom de la Quête_", "_CID_", "Status"],

    "PNJ" : ["_ID_", "Dialogue"],
    "PNJItemTable" : ["_NPCID_", "_Nom d'objet_"],
    "PNJQuestTable" : ["_NPCID_", "_Nom de la Quête_"],

    "Monstre" : ["_Nom_", "Attaque", "Défense", "PV"],
    "MonstreDropTable" : ["_Nom du Monstre_", "_Nom d'objet_", "_Quantitée_", "Probabilité"],

}

s = ""
for k in jaaaj.keys():
	v = jaaaj[k];
	s = ""
	s += f"CREATE TABLE {k.lower()}(\n"
	for p in v:
		s += f"\t{p} INT,\n"
	s += f");"
	print(s)
