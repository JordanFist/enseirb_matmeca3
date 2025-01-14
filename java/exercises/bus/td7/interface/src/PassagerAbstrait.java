package tec;

abstract class PassagerAbstrait implements Passager, Usager{
    private String nom;
    private final int destination;
    private Position pos;
    private final Arret comportementArret;

    PassagerAbstrait(String n, int dest, Arret comportementArret) throws IllegalArgumentException {
        if (dest < 0)
            throw new IllegalArgumentException();
        else {
            nom = n;
            destination = dest;
	    this.pos = Position.create();
            this.comportementArret = comportementArret;
        }
    }

    protected int distanceDest(int numeroArret) {
        return (destination - numeroArret);
    }

    public void changerEnAssis(){
	this.pos = Position.create();
        this.pos = this.pos.assis();
    }

    public void changerEnDebout(){
	this.pos = Position.create();
        this.pos = this.pos.debout();
    }

    public void changerEnDehors(){
	this.pos = Position.create();
    }

    public boolean estAssis(){
	return this.pos.estAssis();
    }

    public boolean estDebout(){
	return this.pos.estDebout();
    }

    public boolean estDehors(){
	return this.pos.estDehors();
    }

    abstract void choixPlaceMontee(Vehicule v);

    public void monterDans(Transport t) throws TecException {
	Vehicule v = (Vehicule) t;
	
	if (!(v instanceof Vehicule))
	    throw new TecException("Erreur lors de la conversion de type");

	try {
	    choixPlaceMontee(v);
	} catch (IllegalStateException e) {
	    throw new TecException(e);
	}
	
    }

    public void nouvelArret(Vehicule v, int numeroArret){
	comportementArret.choixPlaceArret(this, v, distanceDest(numeroArret));
	if (distanceDest(numeroArret) == 0)
	    v.arretDemanderSortie(this);
    }

    public String nom(){
    	return this.nom;
    }

    public String toString() {
        return ("destination: " + destination + " position: " + pos);
    }
}
