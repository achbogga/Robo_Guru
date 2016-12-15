import com.sun.speech.freetts.Voice;
import com.sun.speech.freetts.VoiceManager;
import com.sun.speech.freetts.audio.JavaClipAudioPlayer;
import com.sun.speech.freetts.Age;

public class Basnik {
  String voiceName = "kevin16";
  VoiceManager voiceManager;
  Voice voice;
  Age age = Age.CHILD;
    
  Basnik(String name){
    voiceName = name;     
    this.setup(); 
  }
  
  void listAllVoices() {
    System.out.println();
    System.out.println("All voices available:");
    System.setProperty("mbrola.base", "C:/Users/achyu/Desktop/HRI Project/mbrola");	  
    VoiceManager voiceManager = VoiceManager.getInstance();
    Voice[] voices = voiceManager.getVoices();
    for (int i = 0; i < voices.length; i++) {
	System.out.println("    " + voices[i].getName()
	  + " (" + voices[i].getDomain() + " domain)");
    }
  }

  void setup() {
    listAllVoices();
    System.out.println();
    System.out.println("Using voice: " + voiceName);

    voiceManager = VoiceManager.getInstance();
    voice = voiceManager.getVoice(voiceName);	

    //voice.setPitch(10);
    //voice.setPitchShift(5);
    //voice.setAge(age);
    //voice.setPitchRange(10.1); //mutace
    voice.setStyle("casual");  //"business", "casual", "robotic", "breathy"

    if (voice == null) {
	System.err.println(
	"Cannot find a voice named "
	  + voiceName + ".  Please specify a different voice.");
	System.exit(1);
    }	
    voice.allocate();
  }

  void mluv(String _a){     

    if(_a==null){
	_a= "nothing"; 
    }
    voice.speak(_a);

  }

  void exit(){
    voice.deallocate();  
  }
}