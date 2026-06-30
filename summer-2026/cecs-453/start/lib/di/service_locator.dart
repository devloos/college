import 'package:get_it/get_it.dart';
import 'package:firebase_auth_flutterfire_ui/repository/note_repository.dart';

final getIt = GetIt.instance;

void setupLocator() {
  getIt.registerLazySingleton(() => NoteRepository());
}
