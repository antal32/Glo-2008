/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pièce.
 * \author Antoine Talbot
 * \version 2
 * \date février 2021
 *
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string>
#include <list>	// pour utiliser la liste de la STL

#include "Porte.h"

namespace TP1
{
/**
 *  \class Piece
 *  \brief classe représentant une pièce dans un labyrinthe
 */
class Piece
{
public:


    /**
  * \brief constructeur avec paramètres
     */
	Piece();


    /**
  * \brief Surcharge du constructeur, le nom de la pièce en argument
     */

	Piece(const std::string & s);


    /**
  * \brief constructeur de copie
     */

	Piece(const Piece& source);


    /**
  * \brief destructeur
     */
	~Piece();


    /**
  * \brief Surcharge de l'opérateur =
     */

	const Piece& operator =(const Piece& source);


    /**
  * \brief Accesseur du nom d'une pièce
     */
	std::string getNom() const;


    /**
  * \brief Pour initialiser l'attribut parcourue à true ou false
     */
    void setParcourue(bool p);



    /**
  * \brief Pour initialiser l'attribut distanceDuDebut
     */
	void setDistanceDuDebut(int d);



    /**
  * \brief Acceder au membre parcourue
     */
    bool getParcourue() const;

    /**
* \brief Accéder à la liste des portes qui partent de la pièce
 */
	const std::list<Porte> & getPortes() const;


    /**
* \brief Accéder au membre distanceDuDebut
 */

	int getDistanceDuDebut() const;



    /**
* \brief Ajouter une porte à la liste des portes qui partent de la pièce
 */
 void ajoutePorte(const Porte& p);

private:
	std::list<Porte> portes; /*!< Les portes qui partent de la pièce. */
	/*!<Cette liste peut ne pas contenir toutes les portes qui
	communiquent avec la pièce. Une partie de ces portes peut être placée dans la liste de portes
	de l'autre pièce associée à la porte (utilise la liste STL).*/

	bool parcourue; /*!< Indique si la pièce a été parcourue*/
	/*!< Le champ "parcourue" sert uniquement à la méthode solutionner() de la classe labyrinthe, afin de ne pas passer
	plusieurs fois par une même pièce et risquer de tourner en rond, et donc boucler sans fin. */

	std::string nom; /*!< Le nom de la pièce. Il doit être unique pour un même labyrinthe.*/

	int distanceDuDebut; /*!< Le nombre de déplacements qu'il est nécessaire d'effectuer depuis la pièce de départ pour se rendre à cette pièce. */

};

}

#endif /* PIECE_H_ */
