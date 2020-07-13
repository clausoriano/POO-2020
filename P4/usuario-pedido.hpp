//
// Created by Claudia Soriano Roldán on 15/05/2019.
//

#ifndef P3_USUARIO_PEDIDO_H
#define P3_USUARIO_PEDIDO_H

#include <map>
#include <set>
#include <utility>
#include "pedido.hpp"
#include "usuario.hpp"

class Usuario_Pedido{
public:
    typedef std::set<Pedido*> Pedidos;

    void asocia(Pedido& p, Usuario& user);
    void asocia(Usuario& user, Pedido& p);

    Pedidos pedidos(Usuario& user);
    Usuario* cliente(Pedido& p);

private:
    std::map<Pedido*, Usuario*> peduser_;
    std::map<Usuario*, Pedidos> userped_;

};
typedef std::set<Pedido*> Pedidos;
inline void Usuario_Pedido::asocia(Pedido &p, Usuario &user)
{
    userped_[&user].insert(&p);
    peduser_[&p] = &user;
}

inline void Usuario_Pedido::asocia(Usuario &user, Pedido &p)
{
    return asocia(p, user);
}

inline Pedidos Usuario_Pedido::pedidos(Usuario& user) {return userped_[&user];}
inline Usuario* Usuario_Pedido::cliente(Pedido& p) {return peduser_[&p];}



#endif //P3_USUARIO_PEDIDO_H
