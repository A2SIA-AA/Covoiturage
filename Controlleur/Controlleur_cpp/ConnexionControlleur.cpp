
void ConnexionControlleur::verifierUtilisateur(std::string email, std::string motPasse){

 if( baseDeDonnees.getUtilisateurByEmailAndMDP(email, motPasse) != nullptr ){
      std::cout << "Connexion réussie !" << std::endl;
else {
     std::cout << "Connexion echoué votre email ou mot de passe est incorrect !" << std::endl;;
     };
}
