import java.util.ArrayList;
import java.util.List;

public class Run {
    List<Note> notes = new ArrayList<Note> (); 
    int duration = 0;
    char note;
    int octave;
    boolean newBar = true;
    int barLength = String.valueOf("-------------------------").length();
    int songLength = 0;
    StringBuilder cleanedSong = new StringBuilder("");
    int ci = 0;
    public Run(String song) {
        //System.out.println(song);
        for (int i = 0; i < song.length(); i++) {
            char c = song.charAt(i);
            //System.out.println(c);
            
            switch (c) {
                case '8':
                    i++;
                    goBack();
                    octave = 8;
                    break;
                case '7':
                    i++;
                    goBack();
                    octave = 7;
                    break;
                case '6':
                    i++;
                    goBack();
                    octave = 6;
                    break;
                case '5':
                    i++;
                    goBack();
                    octave = 5;
                    break;
                case '4':
                    i++;
                    goBack();
                    octave = 4;
                    break;
                case '3':
                    i++;
                    goBack();
                    octave = 3;
                    break;
                case '2':
                    i++;
                    goBack();
                    octave = 2;
                    break;
                case '1':
                    i++;
                    goBack();
                    octave = 1;
                    break;
                case '|':
                    break;
                case 10:
                    if (song.charAt(i+2) == 10) {
                        i += 2;
                        System.out.println("new bar");
                        newBar = true;
                    } else {
                        newBar = false;
                    }
                    break;
                case 13:
                    break;
                default:
                    //songLength++;
                    switch (c) {
                        case '-':
                            addChar(c);
                            break;
                        case 'a':
                            note = 'a';
                            addChar(c);
                            break;
                        case 'b':
                            note = 'b';
                            addChar(c);
                            break;
                        case 'c':
                            note = 'c';
                            addChar(c);
                            break;
                        case 'd':
                            note = 'd';
                            addChar(c);
                            break;
                        case 'e':
                            note = 'e';
                            addChar(c);
                            break;
                        case 'f':
                            note = 'f';
                            addChar(c);
                            break;
                        case 'g':
                            note = 'g';
                            addChar(c);
                            break;
                        case 'A':
                            note = 'A';
                            addChar(c);
                            break;
                        case 'B':
                            note = 'B';
                            addChar(c);
                            break;
                        case 'C':
                            note = 'C';
                            addChar(c);
                            break;
                        case 'D':
                            note = 'D';
                            addChar(c);
                            break;
                        case 'E':
                            note = 'E';
                            addChar(c);
                            break;
                        case 'F':
                            note = 'F';
                            addChar(c);
                            break;
                        case 'G':
                            note = 'G';
                            addChar(c);
                            break;
                    }
            }
            // System.out.println(song.charAt(i));
            // System.out.println((int)song.charAt(i));
            // System.out.println(songLength);
            
        }
        System.out.println(cleanedSong.toString());

        for (int i = 0; i < cleanedSong.length(); i++) {
            char c = cleanedSong.charAt(i);

            switch (c) {
                
                case '8':
                    addNote();
                    octave = 8;
                    duration = 0;
                    break;
                case '7':
                    addNote();
                    octave = 7;
                    duration = 0;
                    break;
                case '6':
                    addNote();
                    octave = 6;
                    duration = 0;
                    break;
                case '5':
                    addNote();
                    octave = 5;
                    duration = 0;
                    break;
                case '4':
                    addNote();
                    octave = 4;
                    duration = 0;
                    break;
                case '3':
                    addNote();
                    octave = 3;
                    duration = 0;
                    break;
                case '2':
                    addNote();
                    octave = 2;
                    duration = 0;
                    break;
                case '1':
                    addNote();
                    octave = 1;
                    duration = 0;
                    break;
                case 'a':
                    note = c;
                    duration = 1;
                    break;
                case 'b':
                    note = c;
                    duration = 1;
                    break;
                case 'c':
                    note = c;
                    duration = 1;
                    break;
                case 'd':
                    note = c;
                    duration = 1;
                    break;
                case 'e':
                    note = c;
                    duration = 1;
                    break;
                case 'f':
                    note = c;
                    duration = 1;
                    break;
                case 'g':
                    note = c;
                    duration = 1;
                    break;
                case 'A':
                    note = c;
                    duration = 1;
                    break;
                case 'B':
                    note = c;
                    duration = 1;
                    break;
                case 'C':
                    note = c;
                    duration = 1;
                    break;
                case 'D':
                    note = c;
                    duration = 1;
                    break;
                case 'E':
                    note = c;
                    duration = 1;
                    break;
                case 'F':
                    note = c;
                    duration = 1;
                    break;
                case 'G':
                    note = c;
                    duration = 1;
                    break;
                case '-':
                    i++;
                    duration++;
                    break;
            }
        }
        addNote();
        //notes.forEach((n) -> n.make());
        for (int i = 0; i < notes.size(); i++) {
            notes.get(i).make();
        }
        

    }

    public void goBack() {
        if (!newBar) {
            //System.out.println(ci + " " + cleanedSong.toString());
            ci -= barLength+1;
        }
    }

    public void addChar(char c) {
        if (newBar) {
            if (c == '-') {
                cleanedSong.append(c);
                cleanedSong.append('_');
            } else {
                cleanedSong.append(octave);
                cleanedSong.append(c);
            }
        } else {
            if (c != '-') {
                cleanedSong.setCharAt(ci*2, Character.forDigit(octave, 10));
                cleanedSong.setCharAt(ci*2+1, c);
            }
        }
        ci++;
    }

    public void addNote() {
        if (duration > 0) {
            notes.add(new Note(octave, note, duration));
        }
    }
}
