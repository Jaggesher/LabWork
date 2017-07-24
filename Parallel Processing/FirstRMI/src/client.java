import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		client ob = new client();
		ob.connectToServer();
	}

	private void connectToServer() {
		// TODO Auto-generated method stub
		try {
			Registry reg1=LocateRegistry.getRegistry("localhost",1098);
			Registry reg2=LocateRegistry.getRegistry("localhost",1099);
			String registryURL1="rmi://localhost"+1098+"server";
			String registryURL2="rmi://localhost"+1099+"server";
			
			
			ADD add =(ADD) reg1.lookup(registryURL1);
			System.out.println("Connected To ADD server");
			System.out.println("Summetion is= "+ add.addIT(12, 23));
			
			SUB sub=(SUB) reg2.lookup(registryURL2);
			System.out.println("Connected To SUB Server");
			System.out.println("Subtraction is= "+ sub.subIT(23,12));
			
			
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e);
		}
		
	}
	
}
