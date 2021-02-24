/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date février 2021
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"

namespace TP1
{
 using namespace std;


// -------------------------------------------------------------------------------------------------
//	Méthodes fournies
// -------------------------------------------------------------------------------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
{
	int nbCols, nbRangs;

    if (!entree.is_open())
        throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

	entree >> nbCols >> nbRangs;
	entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

	const int MAX_LIGNE = 1000;
	char ligne[MAX_LIGNE];

	entree.getline(ligne, MAX_LIGNE);
	entree.getline(ligne, MAX_LIGNE);

	std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

	for (int i = 0; i < nbCols; i++)
	{
		for (int j = 0; j < nbRangs; j++)
		{
			s << i << "," << j;
			Piece p(s.str());
			s.str("");
			ajoutePieceLabyrinthe(p);
		}
	}

	for (int i = 0; i < nbCols; i++)
	{
		if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeDepart(nom);
		}
		if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
				+ 1] == 'A' || ligne[i * 4 + 1] == 'a')
		{
			std::string nom;
			s << i << ",0";
			nom = s.str();
			s.str("");
			placeArrivee(nom);
		}
	}

	for (int j = 0; j < nbRangs; j++)
	{
		entree.getline(ligne, MAX_LIGNE);

		for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
		{
			if (j & 1)
			{
				if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
						+ 1] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
						+ 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
						+ 1] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
			else
			{
				if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
				{
					ajoutePassage(couleur, i - 1, j + 1, i, j);
				}
				if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 2);
				}
				if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
				{
					ajoutePassage(couleur, i, j, i, j + 1);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
						+ 3] == 'd'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeDepart(nom);
				}
				if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
						+ 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
						+ 3] == 'a'))
				{
					std::string nom;
					s << i << "," << j + 1;
					nom = s.str();
					s.str("");
					placeArrivee(nom);
				}
			}
		}
	}
}


/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */
void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
{

	NoeudListePieces *piece1, *piece2;
	string nomPiece1, nomPiece2;
	ostringstream s;

	s << i1 << "," << j1;
	nomPiece1 = s.str();

	s.str("");

	s << i2 << "," << j2;
	nomPiece2 = s.str();

	s.str("");

	piece1 = trouvePiece(nomPiece1);
	piece2 = trouvePiece(nomPiece2);

	Porte nouvellePorte(couleur, &(piece2->piece));

	piece1->piece.ajoutePorte(nouvellePorte);
}


/**
 * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
 * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
 * \param[in]	p La pièce à ajouter
 * \post	la pièce appartient au labyrinthe;
 */
    void Labyrinthe::ajoutePieceLabyrinthe(const Piece& p) {

        Labyrinthe::NoeudListePieces* noeud = new Labyrinthe::NoeudListePieces;
        noeud->piece = p;

        if (dernier == 0)
        {
            noeud->suivant = noeud;
            dernier = noeud;
        }
        else if (!appartient(p)) {
            noeud->suivant = dernier->suivant;
            dernier->suivant = noeud;
        }
    }

    //Mettez l'implémentation de vos autres méthodes ici.

    /**
* \fn     Labyrinthe::Labyrinthe()
* \brief Constructeur par défaut
*/
    Labyrinthe::Labyrinthe()
    {
        depart = 0;
        arrivee = 0;
        dernier = 0;
    }
    /**
* \fn Labyrinthe(const Labyrinthe &source)
* \brief constructeur de copie
* \param[in] source
*/
    Labyrinthe::Labyrinthe(const Labyrinthe &source)
    {
        *this = source;
    }

    /**
    * \fn Labyrinthe::~Labyrinthe()
    * \brief Destructeur
    */
    Labyrinthe::~Labyrinthe()
    {
        NoeudListePieces *noeudActuel = dernier;
        NoeudListePieces *noeudSupprimer;
        do
        {
            noeudSupprimer = noeudActuel;
            noeudActuel = noeudActuel ->suivant;
            delete noeudSupprimer;
        } while (noeudActuel != dernier);
    }

    /**
* \fn const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
* \brief Surcharge de l'opérateur =
* \param[in] source
*/
    const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
    {
        depart=source.depart;
        arrivee=source.arrivee;
        dernier=source.dernier;
    }




    /**
* \fn int Labyrinthe::solutionner(Couleur joueur)
* \brief Cette méthode doit solutionner un labyrinthe pour le joueur spécifié par joueur.
* \param[in] joueur
*/
    int Labyrinthe::solutionner(Couleur joueur)
    {
        int compteur = 0;
        NoeudListePieces *noeudActuel = dernier;
        do{
            noeudActuel = noeudActuel -> suivant;
            noeudActuel ->piece.setParcourue(false);
            noeudActuel ->piece.setDistanceDuDebut(-1);
        }
        while (noeudActuel!= dernier);
        queue<Piece*> file;
        file.push(depart);
        list<Porte>::const_iterator monIterator;
        Piece* pieceActuel;
         depart -> setDistanceDuDebut(compteur);
         depart -> setParcourue(true);
        while (!file.empty())
        {
            pieceActuel = file.front();
            file.pop();
            for (monIterator = pieceActuel->getPortes().begin(); monIterator != pieceActuel -> getPortes().end(); ++monIterator)
            {
                if (!monIterator->getDestination()->getParcourue() && monIterator->getCouleur() == joueur)
                {
                    monIterator->getDestination()->setParcourue(true);
                    monIterator->getDestination()->setDistanceDuDebut(pieceActuel->getDistanceDuDebut() +1);
                    file.push(monIterator->getDestination());
                }
            }
        }
        return arrivee->getDistanceDuDebut();

    }




    /**
* \fn Couleur Labyrinthe::trouveGagnant()
* \brief Cette méthode devra appeler quatre fois la méthode solutionner(), une fois par couleur
*/
    Couleur Labyrinthe::trouveGagnant() {
        Couleur  gagnant = Aucun;
        int rouge,vert,bleu,jaune,minimum;
        rouge = solutionner(Rouge);
        vert = solutionner(Vert);
        jaune = solutionner(Jaune);
        bleu = solutionner(Bleu);
        minimum = -1;
        if(jaune != -1){
            gagnant = Jaune;
            minimum = jaune;
        }
        if(bleu != -1 && (bleu <= minimum || minimum == -1)){
            gagnant = Bleu;
            minimum = bleu;
        }
        if(vert != -1 && (vert <= minimum || minimum == -1)){
            gagnant = Vert;
            minimum = vert;
        }
        if(rouge != -1 && (rouge <= minimum || minimum == -1)){
            gagnant = Rouge;
        }

        return gagnant;
    }





    /**
* \fn bool Labyrinthe::appartient(const Piece &p) const
* \brief Vérifie si une pièce portant le nom de la pièce fournie se trouve dans le labyrinthe
* \param[in] p
*/
    bool Labyrinthe::appartient(const Piece &p) const {
        try
        {
            trouvePiece(p.getNom());
            return true;
        }
        catch (logic_error)
        {
            return false;
        }
    }


    /**
* \fn void Labyrinthe::placeDepart(const string &nom)
* \brief Méthode privée, elle sert pour charger un labyrinthe
* \param[in] nom
*/
void Labyrinthe::placeDepart(const string &nom)
    {
        try
        {
            depart = &(trouvePiece(nom)->piece);
        }
        catch (logic_error erreur)
        {
            throw logic_error(erreur.what());
        }
    }



    /**
* \fn void Labyrinthe::placeArrivee(const string &nom)
* \brief Même chose que pour la fonction placeDepart décrite plus haut, mais pour le pointeur arrivee d'un labyrinthe.
* \param[in] nom
 */
    void Labyrinthe::placeArrivee(const string &nom)
    {
        try
        {
            arrivee = &(trouvePiece(nom)->piece);
        }
        catch (logic_error erreur)
        {
            throw logic_error(erreur.what());
        }
    }
    /**
* \fn Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const
* \brief Méthode privée. Retourne l'adresse du noeud de la liste de pièces contenue dans le labyrinthe
* \param[in] nom
 */
    Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const {
        if (std::string(nom).empty())
        {
            throw invalid_argument("Le parametre nom doit contenir un élément.");
        }
        NoeudListePieces *noeudActuel = dernier;
        bool chercher = false;
        do {
            noeudActuel = noeudActuel->suivant;
            if ((*noeudActuel).piece.getNom() == nom) {
                chercher = true;
                break;
            }
        } while (noeudActuel != dernier);
        if (!chercher)
        {
            throw logic_error("Aucune piece avec ce nom ne correspond");
        }
        return noeudActuel;
    }


}//fin du namespace
