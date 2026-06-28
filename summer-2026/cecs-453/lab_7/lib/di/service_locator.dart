import 'package:get_it/get_it.dart';
import 'package:sqflite_note_saver/repository/note_repository.dart';

final getIt = GetIt.instance;

void setupLocator() {
  getIt.registerLazySingleton(() => NoteRepository());
}
