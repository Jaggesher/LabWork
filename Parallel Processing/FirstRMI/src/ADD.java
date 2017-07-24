import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ADD extends Remote{
	public int addIT(int a,int b) throws RemoteException; 
}
