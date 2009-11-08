Итоговый вариант все нормально, вдруг кому-то пригодиться:
static bool CheckCanAccessTheFile(FileSystemInfo fileInfo)
{
DateTime InitializeTime = DateTime.Now;
Thread thread = new Thread(CanAccessTheFile);
thread.IsBackground = true;
thread.Start(fileInfo.FullName);
do
{
TimeSpan ThreadAliveTime = (DateTime.Now - InitializeTime);
if (ThreadAliveTime.Minutes > 4)
{
thread.Abort();
return false;
}
Thread.Sleep(1000);
} 
while (thread.IsAlive);
return true;
}





static void CanAccessTheFile(object FullName)
{
FileStream fs = File.Open(FullName.ToString(), FileMode.Open, FileAccess.Read, FileShare.None);
BinaryReader binaryReader = new BinaryReader(fs);
fs.Seek(0, SeekOrigin.Begin);
try
	{
	const int chunk_size = 1024;
	int ReadedBytes = 0;
	do
		{
		binaryReader.ReadBytes(chunk_size);
		ReadedBytes += chunk_size;
		} 
	while (binaryReader.BaseStream.Length > ReadedBytes);
	}

catch (EndOfStreamException e)
	{
	Console.WriteLine("{0} caught and ignored. " +
	"Using default values.", e.GetType().Name);
	}

catch (Exception)
	{
	System.Threading.Thread.Sleep(new TimeSpan(0,0,5,0));
	}

finally
	{
	binaryReader.Close();
	fs.Close();
	fs.Dispose();
	if (binaryReader.BaseStream != null) binaryReader.BaseStream.Dispose();
	}
}