import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Sample extends Remote{
	public byte[] ProcessIT(byte[] image)throws RemoteException;
}
