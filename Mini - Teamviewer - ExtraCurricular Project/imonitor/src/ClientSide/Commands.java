package ClientSide;

public enum Commands {
	//Used for identifying possible user commands 
	//Example: key press for typing text and so on
	MOVE_MOUSE(-5), 
	PRESS_MOUSE(-1),
	RELEASE_KEY(-4),
	PRESS_KEY(-3),
	RELEASE_MOUSE(-2);
	
	private int abbreviation;
	
	Commands(int abbrev){
		this.abbreviation = abbrev;
	}
	
	public int getAbbrev() {
		return this.abbreviation;
	}
}
