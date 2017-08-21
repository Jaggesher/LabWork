import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class FourthServer extends UnicastRemoteObject implements Sample {

	protected FourthServer() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Registry reg=LocateRegistry.createRegistry(1099);
			String registryURL="rmi://localhost"+1099+"server";
			reg.rebind(registryURL, new FourthServer());
			System.out.println("Server 4 is UP");
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
