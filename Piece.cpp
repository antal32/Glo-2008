/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Antoine Talbot
 * \version 2
 * \date février 2021
 */

#include "Piece.h"
using namespace std;
namespace TP1
{

	//Mettez l'implémentation de vos méthodes ici.
    /**
   *\fn Piece::ajoutePorte(const Porte &p)
   * \brief Ajouter une porte à la liste des portes qui partent de la pièce
     * * \param[in] p, parametre d'identification de la porte
    */
    void Piece::ajoutePorte(const Porte &p)
    {
        for(list <Porte>::iterator monIterateur = portes.begin(); monIterateur != portes.end(); ++monIterateur){
            if (*monIterateur == p )
                return;
        }
        portes.push_back(p);

         Porte porteInverse(p.getCouleur(), this);
        p.getDestination()->ajoutePorte(porteInverse);

    }

    /**
*\fn Piece::Piece()
* \brief Constructeur par default
    */
    Piece::Piece() {}


    /**
*\fn Piece::~Piece()
* \brief Destructeur
 */
    Piece::~Piece() {}

    /**
    *\fn Piece::Piece(const Piece &source)
    * \brief Constructeur de copie
    */
    Piece::Piece(const Piece &source)
    {*this = source;}




    /**
*\fn Piece::Piece(const string &s) :nom(s)
* \brief Surcharge du constructeur, le nom de la pièce en argument
* \param[in] s, le nom de la pièce en argument
 */
    Piece::Piece(const string &s) :nom(s){}




    /**
* \fn const Porte &Porte::operator=(const Porte &source)
* \brief Surcharge de l'opérateur =
* \param[in] source, source, De ou il est arrivé et qui est arrivé
*/
    const Piece &Piece::operator=(const Piece &source)
    {
        nom = source.nom;
        distanceDuDebut = source.distanceDuDebut;
        parcourue = source.parcourue;
        portes = source.portes;
    }




    /**
* \fn std::string Piece::getNom() const
* \brief Accesseur du nom d'une pièce
 */
    std::string Piece::getNom() const
    {
        return  nom;
    }



    /**
* \fn void Piece::setParcourue(bool p)
* \brief Pour initialiser l'attribut parcourue à true ou false
* \param[in] p
   */
    void Piece::setParcourue(bool p)
    {
        parcourue = p;
    }




    /**
* \fn     void Piece::setDistanceDuDebut(int d)
* \brief Pour initialiser l'attribut distanceDuDebut
** \param[in] d
    */
    void Piece::setDistanceDuDebut(int d)
    {
        distanceDuDebut = d;
    }


    /**
* \fn     bool Piece::getParcourue() const
* \brief Acceder au membre parcourue
    */
    bool Piece::getParcourue() const
    {
        return parcourue;
    }



    /**
* \brief Accéder à la liste des portes qui partent de la pièce
*/

    const std::list<Porte> &Piece::getPortes() const
    {
        return portes;
    }
    /**
* \brief Accéder à la distance du début
*/
    int Piece::getDistanceDuDebut() const
    {
        return distanceDuDebut;
    }



}
