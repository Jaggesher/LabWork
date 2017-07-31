import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class Server extends UnicastRemoteObject implements Sample {

	protected Server() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Registry reg=LocateRegistry.createRegistry(1098);
			String registryURL="rmi://localhost"+1098+"server";
			reg.rebind(registryURL, new Server());
			System.out.println("Server is UP");
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e);
		}
	}

	@Override
	public byte[] ProcessIT(byte[] image) throws RemoteException {
		// TODO Auto-generated method stub
		
		System.out.println("Byte Image Just Received");
		return image;
	}

}
