package GamesTest;

public class Games {  
	public static void main(String[] args) {   
		Game[] games = new Game[3];   
		games[0] = new Basketball();   
		games[1] = new Football();   
		games[2] = new Popolong();  
		for(int i=0;i<games.length;i++)
		{    
			if(games[i]!=null)
				games[i].play();   
		}
	}
}