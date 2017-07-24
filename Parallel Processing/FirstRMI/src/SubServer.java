import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

@SuppressWarnings("serial")
public class SubServer extends UnicastRemoteObject implements SUB {

	protected SubServer() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Registry reg=LocateRegistry.createRegistry(1099);
			String registryURL="rmi://localhost"+1099+"server";
			reg.bind(registryURL, new SubServer());
			System.out.println("Sub server Is UP");
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e);
		}
	}

	@Override
	public int subIT(int a, int b) throws RemoteException {
		// TODO Auto-generated method stub
		return (a-b);
	}

}
