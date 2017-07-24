import java.rmi.Remote;
import java.rmi.RemoteException;

public interface SUB extends Remote{
	public int subIT(int a,int b) throws RemoteException;
}
