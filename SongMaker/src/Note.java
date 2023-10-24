public class Note {
    int octave;
    char note;
    int duration;
    public Note(int octave, char note, int duration) {
        this.octave = octave;
        this.note = note;
        this.duration = duration;
    }

    public void print() {
        System.out.println(octave + " " + note + " "+ duration);
    }

    public void make() {
        System.out.print("NOTE_");
        switch(note) {
            case 'a':
                System.out.print("A");
                break;
            case 'b':
                System.out.print("B");
                break;
            case 'c':
                System.out.print("C");
                break;
            case 'd':
                System.out.print("D");
                break;
            case 'e':
                System.out.print("E");
                break;
            case 'f':
                System.out.print("F");
                break;
            case 'g':
                System.out.print("G");
                break;
            case 'A':
                System.out.print("A" + "S");
                break;
            case 'B':
                System.out.print("B" + "S");
                break;
            case 'C':
                System.out.print("C" + "S");
                break;
            case 'D':
                System.out.print("D" + "S");
                break;
            case 'E':
                System.out.print("E" + "S");
                break;
            case 'F':
                System.out.print("F" + "S");
                break;
            case 'G':
                System.out.print("G" + "S");
                break;
        }

        System.out.print(octave + ", " + duration + ", ");
    }
}


