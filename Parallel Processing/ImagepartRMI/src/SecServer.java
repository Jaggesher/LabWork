import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class SecServer extends UnicastRemoteObject implements Sample {

	protected SecServer() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Registry reg=LocateRegistry.createRegistry(1097);
			String registryURL="rmi://localhost"+1097+"server";
			reg.rebind(registryURL, new SecServer());
			System.out.println("Server 2 is UP");
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
