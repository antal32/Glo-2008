/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author Antoine Talbot
 * \version 2
 * \date février 2021
 *
 */

#ifndef PORTE_H_
#define PORTE_H_


namespace TP1
{
/**
 * \enum Couleur
 * \brief La couleur d'un joueur
 *
 * elle peut prendre 5 valeurs : Rouge, Bleu, Jaune ou Vert ainsi que la
 * valeur "Aucun" qui est une valeur spéciale utilisée dans la fonction "trouveGagnant".
 */
typedef enum
{
	Rouge, Vert, Bleu, Jaune, Aucun
} Couleur;

// La ligne qui suit sert à signifier au compilateur que la classe "Piece" existe.
// On le fait, car la structure "Porte" comporte des pointeurs vers la classe "Piece", et vice versa.
class Piece;

/**
 * \class Porte
 * \brief classe qui représente une porte d'une couleur donnée entre deux pièces
 */

class Porte
{
public:

    /**
 * \brief constructeur avec paramètres
    */
    Porte();
    /**
 * \brief Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
    */
    Porte(Couleur c, Piece * d);

    /**
 * \brief constructeur de copie
    */
    Porte(const Porte&);

    /**
 * \brief Destructeur
    */
    ~Porte();

    /**
 * \brief Surcharge de l'opérateur =
    */
    const Porte& operator =(const Porte& source);

    /**
 * \brief Surcharge de l'opérateur ==
    */
    bool operator ==(const Porte& source) const;
    /**
 * \brief accesseur de la couleur d'une porte
    */

    Couleur getCouleur() const;

    /**
* \brief Accesseur de la piece de destination
*/

    Piece * getDestination() const;

private:
    Piece * destination; /*!< Vers où la porte mène.*/
	Couleur color; /*< Couleur de la porte.*/
	/*!< Cette couleur spécifie en même temps quel est le joueur qui a le droit de franchir cette porte.*/

};

}

#endif /* PORTE_H_ */
