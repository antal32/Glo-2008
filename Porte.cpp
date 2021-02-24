/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Antoine Talbot
 * \version 2
 * \date février 2021
 *
 */

#include "Porte.h"

namespace TP1
{

	//Mettez l'implémentation de vos méthodes ici.

    /**
*\fn Porte::Porte()
* \brief constructeur avec paramètres
 */

    Porte::Porte() {}




    /**
* \fn Porte::Porte(Couleur c, Piece *d) :color(c),destination(d)
* \brief Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
* \param[in] c, La couleur d'une porte
* \param[in] d, La piece de destination
   */
    Porte::Porte(Couleur c, Piece *d) :color(c),destination(d){}




    /**
* \fn Porte::~Porte()
* \brief Destructeur
   */
    Porte::~Porte() {}



    /**
 * \fn bool Porte::operator==(const Porte &source) const
 * \brief Surcharge de l'opérateur ==
 * \param[in] source, De ou il est arrivé et qui est arrivé
     *
    */
    bool Porte::operator==(const Porte &source) const
    {
       return getDestination() == source.getDestination()&&getCouleur() == source.getCouleur();
    }




    /**
 * \fn const Porte &Porte::operator=(const Porte &source)
 * \brief Surcharge de l'opérateur =
 * \param[in] source, source, De ou il est arrivé et qui est arrivé
    */
    const Porte &Porte::operator=(const Porte &source)
    {
        color = source.getCouleur();
        destination = source.getDestination();
    }




    /**
* \fn Porte::Porte(const Porte &source)
* \brief Constructeur de copie
* \param[in] source, source, De ou il est arrivé et qui est arrivé
    */
    Porte::Porte(const Porte &source)
    {
     *this = source;
    }
    /**
 * \fn    Couleur Porte::getCouleur() const
 * \brief accesseur de la couleur d'une porte
    */
    Couleur Porte::getCouleur() const
    {
        return color;
    }
    /**
 * \fn Piece *Porte::getDestination() const
 * \brief Accesseur de la piece de destination
    */
    Piece *Porte::getDestination() const {
        return destination;
    }


}
